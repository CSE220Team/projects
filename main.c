#include "common.h"

int main (int argc, const char *argv[])
{
    FILE *source_file;
    char source_name[MAX_FILE_NAME_LENGTH];
    char date[DATE_STRING_LENGTH];
    
	source_file = init_lister(argv[1], source_name, date); //calls init_lister to initialize file
	
	while(get_source_line(source_file, source_name, date)) //runs until there are no more lines
	{
		
	}
	
    return 0;
}
FILE *init_lister(const char *name, char source_file_name[], char dte[])
{
    time_t timer; //creates a timer
    FILE *file;
	
	struct tm* current_time;  //creates a structure to store time variables
	time(&timer);			  //gets current time
	current_time = localtime(&timer);  //converts time into a structure format
	
	//stores date and time as a string into dte
	strftime(dte, DATE_STRING_LENGTH, "%a %b %d %T %Y", current_time);
	
	file = fopen(name, "r");  //opens the file
    
    
    return file;
}
BOOLEAN get_source_line(FILE *src_file, char src_name[], char todays_date[])
{
    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
    char source_buffer[MAX_SOURCE_LINE_LENGTH];
    //static int line_number = 0;
    
	fgets(source_buffer, 80, src_file); //reads the next line of the file
	
	print_line(source_buffer, src_name, todays_date); //calls print_line function
	
	//checks to see if there are any lines left in the file
    if (feof(src_file) == 0)  
    {
        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}

