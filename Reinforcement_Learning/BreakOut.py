import gym
from stable_baselines3 import A2C
from stable_baselines3.common.vec_env import vec_frame_stack
from stable_baselines3.common.evaluation import evaluate_policy
from stable_baselines3.common.env_util import make_atari_env
import os

environment_name = 'Breakout-v0'
env = gym.make(environment_name)