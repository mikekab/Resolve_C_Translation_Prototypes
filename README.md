Facility Rev_Stack_Stack;
-- an example of a stack with an enhancement and read/write
    Facility Stack_Fac is Stack_Template(Integer, 4)
            realized by Array_Realiz
    	enhanced by Reading_Capability
	        realized by Obvious_Reading_Realiz(Std_Integer_Fac.Read)
	    enhanced by Writing_Capability
	        realized by Obvious_Writing_Realiz (Std_Integer_Fac.Write);
    Facility StackStackFac is Stack_Template(Stack_Fac.Stack, 2)
        realized by Clean_Array_Realiz;

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

end Rev_Stack_Stack;
