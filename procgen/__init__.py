import os

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
version_path = os.path.join(SCRIPT_DIR, "version.txt")
__version__ = open(version_path).read()

from .env import CProcgenEnv, CProcgenGym3Env
from .gym_registration import register_environments

register_environments()

__all__ = ["CProcgenEnv", "CProcgenGym3Env"]
