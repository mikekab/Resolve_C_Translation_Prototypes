
#include "../Common/Integers.h"

//Facility Int_Swap_Example_Fac;
/*
    Operation Exchange(updates I: Integer; updates J: Integer);
        ensures I = #J and J = #I;
    Procedure
        Var Temp: Integer;

        Temp := I;
        I := J;
        J := Temp;
    end Exchange;
*/
void Exchange(Integer* I, Integer* J)
{
    Integer Temp;
    Temp = *I;
    *I = *J;
    *J = Temp;
}
/*
    Operation Exchange2(updates I: Integer; updates J: Integer);
        ensures I = #J and J = #I;
    Procedure
        I := I + J;
        J := I - J;
        I := I - J;
    end Exchange2;
*/
void Exchange2(Integer* I, Integer* J)
{
    *I = *I + *J;
    *J = *I - *J;
    *I = *I - *J;
}
/*
    Operation Main();
    Procedure
        Var X, Y: Integer;
        Write_Line("Input two numbers");
        Read(X);
        Read(Y);
        Exchange(X, Y);
        Write("The first number is:");
        Write(X);
        Write_Line("------------");
        Write("The second number is:");
        Write(Y);
        Write_Line("------------");
        Exchange2(X, Y);
        Write("The first number is:");
        Write(X);
        Write_Line("------------");
        Write("The second number is:");
        Write(Y);
        Write_Line("------------");
    end Main;
end Int_Swap_Example_Fac;
*/
int main()
{
    Integer_Fac* IF = newIntegerFac();
    Integer X, Y;
    printf("Input two numbers\n");
    IF->Read(&X);
    IF->Read(&Y);
    Exchange(&X, &Y);
    printf("The first number is: ");
    IF->Write(X);
    printf("\n------------------\n");
    printf("The second number is: ");
    IF->Write(Y);
    printf("\n------------------\n");
    Exchange2(&X, &Y);
    printf("The first number is: ");
    IF->Write(X);
    printf("\n------------------\n");
    printf("The second number is: ");
    IF->Write(Y);
    printf("\n------------------\n");
    return 0;
}
