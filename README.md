Alt_Rev_Stack is an example of a translation from RESOLVE to C.  The RESOLVE code is loosely based on the Alt_Rev_Stack from the workspace.

Facility Alt_Rev_Stack;
    Facility Stack_Fac is Stack_Template(Integer, 4)
    	    realized by Array_Realiz
    	enhanced by Reading_Capability
	        realized by Obvious_Reading_Realiz(Std_Integer_Fac.Read)
	    enhanced by Writing_Capability
	        realized by Obvious_Writing_Realiz (Std_Integer_Fac.Write);

    Facility StackStackFac is Stack_Template(Stack_Template.Stack, 2)
        realized by Array_Realiz;

    Operation Main();
    Procedure
        Var SS: StackStackFac.Stack;
        Var S1, S2: Stack_Fac.Stack;
        Read(S1);
        Read(S2);
        Push(S1, SS);
        Push(S2, SS);
	    Write_Line("REVERSED ORDER");
	    Pop(S1, SS);
	    Write(S1);
	    Pop(S1, SS);
        Write(S1);
    end Main;

end Alt_Rev_Stack;

The most challenging aspect of the translation is in the implementation of a pseudo-generic type in the code for the stack realization.  The C code compiles without warnings, and does not leak any memory.  The program takes 8 integers from standard input, putting 4 in each stack, then pushes the 2 stacks on another stack.  It then pops the stacks off one at a time and writes their content.
