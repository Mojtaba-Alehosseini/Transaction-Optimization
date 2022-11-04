# Transaction-Optimization
+ Transaction optimization (remove middlemen)
+ Imagine person A should pay x$ to person B and person B should pay x$ to person C. now if person A pays x$ to person C, one less transaction has been done.
+ By generalizing the above problem to n people and each with different amounts, the problem becomes a little complicated and in reality, its calculation will be a little time-consuming and error-prone.
+ This project aims to build a program that can eliminate intermediaries (middlemen) in the best possible way so that in the end the maximum number of relationships between people is half the number of people (which is obvious to prove).
+ On the other hand, we can say it is deriving data structure to eliminate vertices in a tree structure.
+ A simple example:
+ Person A should pay 10$ to person B
+ Person B should pay 10$ to person C
+ Optimized Answer:
+ Person A should pay 10$ to person C
+ 
+ An example:
+ Person A should pay 10$ to person B
+ Person B should pay 20$ to person C
+ Person C should pay 30$ to person D
+ Person D should pay 10$ to person A
+ Optimized Answer:
+ Person B should pay 10$ to person D
+ Person C should pay 10$ to person D
+
+ Please use one character for a person’s name, u can change it to string and use a full name of persons.
+ Password: mojtaba
+ :)

