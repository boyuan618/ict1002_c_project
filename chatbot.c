/*chatbot.c implements the behaviour of the chatbot. It is required to: 
1. Recognise smalltalk and provide an appropriate response. 
2. Otherwise, identify the intent and entity in each line of input from the user. 
3. If the intent is an instruction, carry it out. 
4. If the intent is a question, search the knowledge base (see below) for an answer. 
5. If the knowledge base does not contain an answer, ask the user for an answer, and add 
the new answer to the knowledge base. 
*/