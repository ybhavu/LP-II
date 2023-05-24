# Importing the necessary libraries
from chatterbot import ChatBot
from chatterbot.trainers import ChatterBotCorpusTrainer

# Create a chatbot instance
chatbot = ChatBot('CustomerBot')

# Create a new trainer for the chatbot
trainer = ChatterBotCorpusTrainer(chatbot)

# Train the chatbot on an English corpus
trainer.train("chatterbot.corpus.english")

# Main interaction loop
while True:
    user_input = input("User: ")

    # Get a response from the chatbot
    bot_response = chatbot.get_response(user_input)

    print("ChatBot: " + str(bot_response))
