import datetime
import wikipedia
import webbrowser
import os

def wishMe():
    hour = int(datetime.datetime.now().hour)
    if hour>=0 and hour<12:
        print("Good Morning!")

    elif hour>=12 and hour<18:
        print("Good Afternoon!")   

    else:
        print("Good Evening!")  


if __name__ == "__main__":
    wishMe()
    while True:
        print("Please tell me how may I help you")
        query = input().lower()
        tasks_dict = {
                      "the time": lambda query: print(f"The time is {datetime.datetime.now().strftime('%H:%M:%S')}"),
                      "what is your name": lambda query: print("My name is Ybhav"),
                      "how are you?": lambda query: print("I am fine, Thank you"),
                      "who made you?": lambda query: print("I was built by Ybhav"),
                      "open code": lambda query: os.startfile("C:\\Users\\Ybhav\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe"),
                      "search": lambda query: webbrowser.open("https://www.google.com/search?q="+query.replace("search", "")),
                      "open": lambda query: webbrowser.open(query.replace("open ","")+".com"),
                      "music": lambda query: webbrowser.open("https://www.youtube.com/watch?v=uvCaLfIXrjM&list=RDuvCaLfIXrjM&start_radio=1"),
                      }
                      
        task = None
        for k, v in tasks_dict.items():
            if k in query:
                task = v
                break

        if task:
            task(query)
        else:
            print("I am sorry, I am not able to understand you")
