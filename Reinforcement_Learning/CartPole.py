import os
import gym
from gym import wrappers
from stable_baselines3 import PPO
from stable_baselines3 import DQN
from stable_baselines3.common.vec_env import DummyVecEnv
import tensorboard
from stable_baselines3.common.evaluation import evaluate_policy
from stable_baselines3.common.callbacks import EvalCallback, StopTrainingOnRewardThreshold
# from gym.utils.env_checker import check_env

# Loading the Environment
environment_name = 'CartPole-v0'
# env = gym.make(environment_name)

# Little bit coding
# episodes = 10
# for episode in range(1, episodes + 1):
#     state = env.reset() # Resetting the episode
#     done = False
#     score = 0
#
#     while not done:
#         env.render() # For visualisation
#         action = env.action_space.sample() #Usually we have two action spaces in this code..0 or 1
#         # Next line give us the observations space which include some float32 values, a reward, done tells us that one
#         # episode is complete due to the termination of the agent..Here if done = True    ..Next episode will start
#         # env.step is used for apply an action to the environment
#         n_state, reward, done, info = env.step(action)
#         # Score is accumulating the reward
#         score += reward
#     print('Episode:{} Score:{}'.format(episode, score))
# env.close()

# Made directories first
log_path = os.path.join('Training', 'Logs')
env = gym.make(environment_name)
# Creates a dummy vectorized environment
env1 = DummyVecEnv([lambda: env])
# Here we are using a PPO policy
# model = PPO('MlpPolicy', env1, verbose=1, tensorboard_log=log_path)
# The name of next line is self-explanatory
# model.learn(total_timesteps=20000)
PPO_Path = os.path.join('Training', 'Saved Models', 'PPO_Model_CartPole')
# model.save(PPO_Path)
# print(PPO_Path)
# model.learn(total_timesteps=1000)
model1 = PPO.load(PPO_Path, env=env)
# print(evaluate_policy(model1, env=env1, n_eval_episodes=10, render=True))

## Testing The Model ##
episodes = 15
for episode in range(1, episodes + 1):
    obs = env1.reset()
    done = False
    score = 0

    while not done:
        env.render()
        action, _ = model1.predict(obs)
        obs, reward, done, info = env1.step(action)
        # Score is accumulating the reward
        score += reward
    print('Episode:{} Score:{}'.format(episode, score))
env.close()

training_log_path = os.path.join(log_path, 'PPO_7')

######## Adding a Callback to the training stage #########

save_path = os.path.join('Training', 'Saved Models')
stop_callback = StopTrainingOnRewardThreshold(reward_threshold=200, verbose=1)
eval_callback = EvalCallback(env1, callback_on_new_best=stop_callback, eval_freq=10000,
                             best_model_save_path=save_path, verbose=1)
# model = PPO('MlpPolicy', env1, verbose=1, tensorboard_log=log_path)

# model.learn(total_timesteps=20000, callback=eval_callback)

######## Changing Policies ########

# net_arch = [dict(pi = [128, 128, 128, 128], vf = [128, 128, 128, 128])]
# model = PPO('MlpPolicy', env, verbose=1, tensorboard_log=log_path, policy_kwargs={'net_arch': net_arch})
# model.learn(total_timesteps=20000, callback=eval_callback)


######### Using an Alternate Algorithm ##########
# from stable_baselines3 import DQN
# model = DQN('MlpPolicy', env, verbose=1, tensorboard_log=log_path)
# model.learn(total_timesteps=20000)






