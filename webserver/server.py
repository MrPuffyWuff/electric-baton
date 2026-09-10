from flask import Flask
app = Flask(__name__)

@app.route("/")
@app.route("/home")
def index():
    return "<h1>Hello World!!!</h1> test"

@app.route("/about")
def about():
    return "<h1>ABOUT THE ... WoOOOOOOOORLD!!!</h1> test"

if __name__ == "__main__":
    app.run(debug=True)