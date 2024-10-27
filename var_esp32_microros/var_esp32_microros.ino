#include <micro_ros_arduino.h>
#include <stdio.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <std_msgs/msg/int8.h>
#include <std_msgs/msg/int32.h>
#include <geometry_msgs/msg/twist.h>

rcl_subscription_t subscriber1;
rcl_subscription_t subscriber2;
rcl_subscription_t linearUT_subscriber;
rcl_subscription_t linearBrush_subscriber;
rcl_subscription_t Brush_subscriber;

std_msgs__msg__Int32 msg1;
geometry_msgs__msg__Twist msg2;
std_msgs__msg__Int8 linearUT_msg;
std_msgs__msg__Int8 linearBrush_msg;
std_msgs__msg__Int8 Brush_msg;

rclc_executor_t executor;
rcl_allocator_t allocator;
rclc_support_t support;
rcl_node_t node;
rcl_timer_t timer;

#define UT1 18
#define UT2 19
#define Brush1 16
#define Brush2 17

//right motor
#define ENA 25  // PWM pin for right motor
#define IN1 26  // Direction pin for right motor
//left motor
#define ENB 14  // PWM pin for left motor
#define IN3 27  // Direction pin for left motor

//brush motor
#define PWM 32  // PWM pin for brush motor
#define DIR 33  // Direction pin for brush motor

int speed;

void setMotorSpeed(int speedLeft, int speedRight);
#define RCCHECK(fn) \
  { \
    rcl_ret_t temp_rc = fn; \
    if ((temp_rc != RCL_RET_OK)) { error_loop(); } \
  }
#define RCSOFTCHECK(fn) \
  { \
    rcl_ret_t temp_rc = fn; \
    if ((temp_rc != RCL_RET_OK)) { error_loop(); } \
  }

void error_loop() {
  while (1) {
    delay(100);
  }
}

int limitToMaxValue(int value, int maxLimit) {
  if (value > maxLimit) {
    return maxLimit;
  } else {
    return value;
  }
}

void linearUT_subscription_callback(const void *msgin) {
  const std_msgs__msg__Int8 *msg = (const std_msgs__msg__Int8 *)msgin;

  int8_t value = msg->data;

  switch (value) {
    case 0:
      digitalWrite(UT1, LOW);
      digitalWrite(UT2, LOW);
      break;
    case 1:
      digitalWrite(UT1, HIGH);
      digitalWrite(UT2, LOW);
      break;
    case 2:
      digitalWrite(UT1, LOW);
      digitalWrite(UT2, HIGH);
      break;
    case 3:
      digitalWrite(UT1, HIGH);
      digitalWrite(UT2, HIGH);
      break;
    default:
      break;
  }
}

void Brush_subscription_callback(const void *msgin) {
  const std_msgs__msg__Int8 *msg = (const std_msgs__msg__Int8 *)msgin;

  int8_t value = msg->data;

  switch (value) {
    case 0:
      digitalWrite(PWM, LOW);
      digitalWrite(DIR, LOW);
      break;
    case 1:
      digitalWrite(PWM, HIGH);
      digitalWrite(DIR, LOW);
      break;
    case 2:
      digitalWrite(PWM, LOW);
      digitalWrite(DIR, HIGH);
      break;
    case 3:
      digitalWrite(PWM, HIGH);
      digitalWrite(DIR, HIGH);
      break;  
    default:
      break;
  }
}

void linearBrush_subscription_callback(const void *msgin) {
  const std_msgs__msg__Int8 *msg = (const std_msgs__msg__Int8 *)msgin;

  int8_t value = msg->data;

  switch (value) {
    case 0:
      digitalWrite(Brush1, LOW);
      digitalWrite(Brush2, LOW);
      break;
    case 1:
      digitalWrite(Brush1, HIGH);
      digitalWrite(Brush2, LOW);
      break;
    case 2:
      digitalWrite(Brush1, LOW);
      digitalWrite(Brush2, HIGH);
      break;
    case 3:
      digitalWrite(Brush1, HIGH);
      digitalWrite(Brush2, HIGH);
      break;
    default:
      break;
  }
}

void subscription_callback1(const void *msgin) {
  const std_msgs__msg__Int32 *msg = (const std_msgs__msg__Int32 *)msgin;
  speed = msg->data;
  limitToMaxValue(speed, 230);
}

//twist message cb
void subscription_callback2(const void *msgin) {
  const geometry_msgs__msg__Twist *msg = (const geometry_msgs__msg__Twist *)msgin;

  float linear = msg->linear.x;
  float angular = msg->angular.z;

  analogWrite(ENA, speed);
  analogWrite(ENB, speed);

  if (linear > 0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN3, LOW);
  } else if (linear < 0) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN3, HIGH);
  }

  if (angular > 0) {  // Turn left
    digitalWrite(IN1, HIGH);
    digitalWrite(IN3, HIGH);
  } else if (angular < 0) {  // Turn right
    digitalWrite(IN1, LOW);
    digitalWrite(IN3, LOW);
  }

  if (linear == 0 && angular == 0) {
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
  }
}

void setup() {
  //set_microros_wifi_transports("TP-Link_922A_EXT", "28757641", "192.168.0.144", 8888);
  set_microros_transports();

  pinMode(UT1, OUTPUT);
  pinMode(UT2, OUTPUT);
  pinMode(Brush1, OUTPUT);
  pinMode(Brush2, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN3, OUTPUT);

  pinMode(PWM, OUTPUT);
  pinMode(DIR, OUTPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  digitalWrite(PWM, LOW);
  digitalWrite(DIR, LOW);

  speed = 210;
  delay(2000);

  allocator = rcl_get_default_allocator();

  // create init_options
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));

  // create node
  RCCHECK(rclc_node_init_default(&node, "micro_ros_arduino_node", "", &support));

  // create subscriber
  RCCHECK(rclc_subscription_init_default(
    &linearUT_subscriber,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8),
    "linearUT"));

    // create subscriber
  RCCHECK(rclc_subscription_init_default(
    &Brush_subscriber,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8),
    "Brush"));

  // create subscriber
  RCCHECK(rclc_subscription_init_default(
    &linearBrush_subscriber,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8),
    "linearBrush"));

  // create subscriber for getting motor PWM speed
  RCCHECK(rclc_subscription_init_default(
    &subscriber1,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
    "PWM_motor_speed"));

  // create subscriber for cmd_vel
  RCCHECK(rclc_subscription_init_default(
    &subscriber2,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
    "cmd_vel"));

  // create executor
  RCCHECK(rclc_executor_init(&executor, &support.context, 5, &allocator));
  RCCHECK(rclc_executor_add_subscription(&executor, &subscriber1, &msg1, &subscription_callback1, ON_NEW_DATA));
  RCCHECK(rclc_executor_add_subscription(&executor, &subscriber2, &msg2, &subscription_callback2, ON_NEW_DATA));
  RCCHECK(rclc_executor_add_subscription(&executor, &linearUT_subscriber, &linearUT_msg, &linearUT_subscription_callback, ON_NEW_DATA));
  RCCHECK(rclc_executor_add_subscription(&executor, &linearBrush_subscriber, &linearBrush_msg, &linearBrush_subscription_callback, ON_NEW_DATA));
  RCCHECK(rclc_executor_add_subscription(&executor, &Brush_subscriber, &Brush_msg, &Brush_subscription_callback, ON_NEW_DATA));
}

void loop() {
  delay(10);
  RCCHECK(rclc_executor_spin_some(&executor, RCL_MS_TO_NS(10)));
}
