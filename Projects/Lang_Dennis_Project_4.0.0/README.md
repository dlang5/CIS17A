CIS 17A Final Project

This project improves upon the midterm Connect Four project by including header files, class structures, inheritance, operator overloading, polymorphism, and templates, for a total of 1000+ lines of code (200 lines of useful comments)

Version 1.0.0: Completed Midterm Project with headers and class structures implemented.

Version 1.1.0: Converted functions to class functions with prototypes, made member variables private, bulk of code moved to "Player.h"

Version 1.1.1: Added friend class and aggregation from previous structures.

Version 2.0.0: Added static int gameCounter to count number of games played accessible from any instance of Player. Added accessor getGameCounter to return number of games. Implemented inline overloaded constructor to "empty" Player test. Created new Player test with two arguments in test to show off overloaded constructor.

Version 3.0.0: Implemented "Royal Connect 4" by appending random courtly titles and adjectives given gender.
               Added copy constructor and destructor in the form of an Easter Egg after 5 completed games.
               Implemented exception handling throughout.

Version 3.0.1: More exception handling added.

Version 3.1.0: Included more statistics in the game via a template that outputs the highest number of wins. Included more royal flair, as well as code to say "Good Game" or "Good Games" depending on matches ran.

Version 3.2.0: Added even more royal flair. Split classes into more .h files for easy UML charting. Implemented unique messages based on Rand for loser and tie games. Converted Easter Egg class to use protected variable.

Version 3.2.1: Cleaned up main by adding a few functions.

Version 3.3.0: Brought functions from "Player.h" back to main. Added a prototype virtual void function in Player class. Added a protoype derived Player. Implemented an overloaded "==" operator to compare player names. More functions added to main with prototypes.

Version 4.0.0: Added derived class LoserPlayer for enhanced easter egg using polymorphic virtual function from Player. Easter egg counter better implementation. Removed newFile.h. "Golden" name tag added for players that successfully unlock the Easter egg (using the overloaded + operator to append the string).
