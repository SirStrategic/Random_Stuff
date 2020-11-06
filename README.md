# Random stuff

***
## Simple-String-Parsing

These are two functions I made to parse strings and seperate their arguments. 

The first one is what I would recomend to use, it is about twice as slow as the other one (which is the main reason for why I made the second one) as it uses standard library  `string` and `vector` classes.
The second one is around twice as fast however is a mess. I'm actualy proud that I got it to work as I have little experience with memory managment. This might not be safe to use as it may cause memory leaks (????????) (probably not tho), just make sure to free the memory once it has been used.

If there are any issues with the code then feel free to let me know, or branch or something idk, I don't use git much.

Disclaimer: This is probably not thread and/or exception safe as I have no clue either what they are or how to make them safe. Use at your own risk.

***
## Search-And-Replace

This is another thing I've just descided to upload, it's a tool (if it's even complete enough to call it that) that finds and replaces items in a string while remembering what it's already edited so it doesn't edited alread edited text. Probably usless but I've just copy pasted a cursed program I made to owo text with edited "Targets" to demonstrate the functionality. This is probably inneficient as hell but I have no way of making it better so deal with it.
