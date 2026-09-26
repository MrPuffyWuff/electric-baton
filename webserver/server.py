from flask import Flask, render_template
app = Flask(__name__)

posts = [
    {
            "author": "MrPuffyWuff",
            "title": "My First post",
            "content": "Hmm ya know it might be cool to put community music stuff here",
            "date_posted": "9-15-2026"
        },
    {
            "author": "ILoveGatsbyMusical",
            "title": "second post",
            "content": "yes hi im cool and good at dancing",
            "date_posted": "9-15-2026"
        },
]

@app.route("/")
@app.route("/home")
def index():
    return render_template("home.html", posts=posts)

@app.route("/about")
def about():
    return render_template("about.html")

if __name__ == "__main__":
    app.run(debug=True)