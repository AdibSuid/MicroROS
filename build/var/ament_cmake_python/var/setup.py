from setuptools import find_packages
from setuptools import setup

setup(
    name='var',
    version='0.0.0',
    packages=find_packages(
        include=('var', 'var.*')),
)
