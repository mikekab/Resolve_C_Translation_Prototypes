Resolve_C_Translation_Prototypes
================================

Alt_Rev_Stack:
This is an example facility that uses concepts, realizations, and enhancements.
The facility uses 2 stacks of Integers, and 1 stack of stacks of integers.

The enhancement read is used to fill the 2 Integer stacks, these are then
pushed onto the stack of stacks.

These Integer stacks are popped off one at a time and the enhancement write
displays their contents.

An example run with 2 Integer stacks of depth 4 each looks like this:

1
2
3
4
5
6
7
8
REVERSED ORDER
87654321

Instances of data types such as Stack and Integer contain only their relevant data.
Inclusion of pointers to related functions within the data types is avoided by passing
parameters to their facilities to methods that use the data types.  This is done to 
minimize storage space, and also for the fact that this method seems to be implied
by the RESOLVE language.

Note that this is still a work in progress.  In particular, freeing of dynamically 
allocated memory is not fully implemented.  Another outstanding issue is Integer
functionality.  Integers are so commonly used that the Integer facility should be
globally available or else a reference to one should be included in each Facility.
