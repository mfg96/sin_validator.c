//Muhammad Faraz Sohail
//sin validator

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include <sys/file.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#define SIZE 9 


//read function to read the number the number of character and returning the number of characters
int readLine (int fd, char *buff,int size)
{
	int i=0;
	char ch;
	while(read(fd,&ch,1)){
    //read(fd,&ch,1);
	if(ch != ' ' && ch != '\n'){
		buff[i]=ch;
	i++;}
	else if(ch=='\n')
		break;
}
return i;

}
 
 
int main(int argc, char *argv[])
{
	//int i=0;
	char orig='0';
    int x;
	char msg1[11]=" VALID\n";
	char msg2[11]=" NON VALID\n";
	int check[SIZE]={1,2,1,2,1,2,1,2,1};
    char buf[SIZE];
    int fd=open(argv[1],O_RDONLY);
	
	//checks if there is file given or not
	if(argc!=2){
		perror("Missing Filename\n");
		exit(1);
	}
	
	//checks if the file is there or not
    if(argv[1]==NULL)
    {
        perror("Unable to open the file\n");
        exit(1);
    }
	
	//loop for algorithm and readLine function is called inside the loop body
	while((x=readLine(fd,&buf[0],10))!=0){
		
		buf[x]='\0'; //initializes the last character of buffer to '\0'
		int sum=0; // sum variable to store the sum
		int z=0;
	
		//loop for calculation
	while(buf[z]!='\0'){
		
		//if statement checks that if the numbers are between 0 and 9 as a characters
        if(buf[z]>='0' && buf[z]<='9'){

            int calc = (buf[z]-'0')*check[z]; //converts the char into int and then multiplies by check numbers array

      
			
			//calculates the sum 	
            while(calc>0){
					

                sum += calc%10;

                calc = calc/10;

                         }

        }

        z++;
		
}
	
	//using write to print out statements on console
	write(STDOUT_FILENO,buf,20);
	if(sum%10==0)
		write(STDOUT_FILENO,msg1,11);
	else
		write(STDOUT_FILENO,msg2,11);
	continue;
 
}

close(fd);
    return 0;
}

