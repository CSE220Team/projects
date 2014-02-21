#include "common.h"

static void print_page_header(char source_name[], char date[]);

void print_line(char line[], char source_name_to_print[], char date_to_print[])
{
    char save_ch;
    char *save_chp = NULL;
	static int line_count = MAX_LINES_PER_PAGE + 1;
    
    if (line_count > MAX_LINES_PER_PAGE)
    {
        line_count = 1; //resets line count
		print_page_header(source_name_to_print, date_to_print);  //prints page header
    }
    if (strlen(line) > MAX_PRINT_LINE_LENGTH) 
    {
        save_ch = line[80];    //saves char to be replaced
		line[80] = '\0';       //truncates line at 80 chars
		printf("%d:  %s\n", line_count, line);  //prints the line
		line[80] = save_ch;    //restores the string to original length
		line_count++;		   //updates line count
    }
	else
	{
		printf("%d:  %s\n", line_count, line);  //prints the line
		line_count++;							//updates line count
	}
}
static void print_page_header(char source_name[], char date[])
{
    static int page_number = 0;
	page_number += 1;  //updates page number
	char dir[80];	   //string to store directory
	getcwd(dir, 80);   //gets directory and stores in string
    printf("Page %d\t%s/%s\t%s\n\n\n", page_number, dir, source_name,date);  //prints page header
	
}
