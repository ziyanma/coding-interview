# James Ma's Practical Guide to Coding Interview

## FORWARD
In this guide, I am trying to provide my insights as both an interviewer who has conducted more than 200 interviews, as well as a candidate, who has went through over 100 coding interviews. I want to provide a simple and practical study guide for candidates with limited time, to be able to improve their skills at coding interview.

You might ask: there are leetcode, why is this guide still necessary? Why can't I spend the same time reading this guide, trying to solve problems on leetcode?

Well, at the moment of writing this guide, there are north of 3000 interview questions on leetcode. A candidate with a full-time job simply cannot brute-force all the questions. And, knowing a solution to a question, does NOT mean you pass the interview automatically. Sarcastically, one of the only times I actually encountered a question that I solved before on leetcode, I forgot the solution. I went on to a painful time trying to recall the solution and reasoning, spending a long time coding, and persumably got a weak hiring signal. 

I did pass the interview, though it was by far not the best I was able to do.

In this guide, I am trying my best to answer the following questions with some examples:
- What is an interviewer looking for?
- How to structure your coding interview?
- How to increase your score?
- How to write efficient and practical code in a coding interview?


In this guide, I am not going to do:
- Iterate through every algorithm & data structure that you would need in your interviews.
- Go over insane optimization to beat 100% of leetcode solution (xd).
- Test you on the hardest question you ever seen.
- Discuss anything beyond the scope of coding interview. (Behavior, System Design etc.).

This is probably enough yapping for now, so let's start to have some fun :) 


## What is an interviewer looking for?
The interviewer is typically scoring an interview from the following verticals:
- Problem solving and fundamentals,
- Coding ability,
- Communication,

### Problem solving and fundamentals:
- **Understanding the problem**: A passing candidate should be understanding the core requirements and constraints in a reasonable time. Ask for clarifying questions and constraints. An experienced interviewer should be prepared with some examples for their questions, but even when they don't, a passing candidate should always have the ability to provide examples, a stronger candidate would be able to see the constraints and provide tricky
- **Algorithm & Data Structure**: What are some relevant algorithms and data structure to solve the problem efficiently. This is your fundamentals, and your first chance to showcase your strength. A passing candidate should eventually be able to identify the correct solution with potentially some help from the interviewer, a strong candidate should be able to identify the solution independently, reasoning through it, or discuss a few different solutions with trade offs.
- **Edge Case Handling**: Any functional code should handle edge cases and error cases. A passing candidate would be able to handle error with the guide of the interviewer, a strong candidate would be able to demonstrate their experience in this area voluntarily. In a later chapter of this guide, I will provide a handful of examples on how to best handle error cases.

### Coding Ability:
- **Efficiency & Correctness**: A passing candidate should be able to finish coding with given time. A strong candidate should be able to finish coding early, and have little to none error. This is subjective to the difficulty of question and language you choose, and most interviewer would have horizontal data points to compare with.
- **Readability & Maintanability**: A passing candidate should write at least readable code. A strong candidate should write clean, mantainable code. Most interviewer are also code reviewer at their team! Consider this as a code review exercise, I will write a chapter on this too.
- **Language Familarity**: A passing candidate should write code correctly in chosen language. A strong candidate should show expertise in the chosen language, including but not limited to: standard library usage, array manipulation, etc.

### Communication:
- **Reasoning**: Articulating your approach and reasoning clearly is crucial, even if you don't immediately have the perfect solution. A strong candidate usually can go through their solution, code, when also articulating their thought process and reasoning. This is an important skill, and would require a lot of practicing.
- **Structuring**: An explanation should be structured! Write your bulletin down when you are thinking so you can articulate your solution in a structured way in one iteration. Coding should be structured too, a strong candidate ususally write psudo-code blocks before they replace them one by one.

Now, go back to the last leetcode question that you solved correctly. Did you check all the boxes? Would you make a strong candidate or a passing candidate?





