esatjar@seroiuts01946[16:24][home/esatjar/practice]$ cat time_conversion.c 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(char *s,int nh) {
    if (nh == 0) {
	s[0] = '0';
	s[1] = '0';
	return;
    }
	printf("nh = %d \n ",nh);
	s[1] = (nh % 10) + '0';
	nh = nh / 10;
	s[0] = (nh % 10) + '0';
    return;
}

void timeConversion(char* s) {

    printf("string  = %s \n",s);
    int i ; 
    int nh = 0;
    int  len = strlen(s) - 1;  
    int size = 3;
    char am_pm[size];
    int  j = 1;
 /*
    nh [0] = s[0];
    nh [1] = s[1];

    printf("stringlen = %d",strlen(s));
    am_pm[0] = s[len-1];
    s[len-1] = s[len];
    len--;
    am_pm[1] = s[len];
    s[len] = "\0";
    len--;
    printf("stringlen = %d",strlen(s));
*/ 


    for ( i = 0 ; i < 2 ; i++) {
            nh =  nh * 10 + s[i] - '0';
            am_pm[i] = s[len-j];
	          s[len-j] = s[len];
	          s[len] = '\0';
	          j--;
	          len--;
    }

    am_pm[i] = '\0';
    printf("extracteed am/pm  = %s   nh = %d \n",am_pm, nh);
	if (strcmp("AM",am_pm) == 0) {
	    if (nh == 12) {
		func(s,0);
	    }
	}
	if (strcmp("PM",am_pm) == 0) {
    	     printf("calling func with %s , n h %d\n",am_pm, nh);
	    nh = nh + 12;
	    func(s,nh);
	}
    printf("convered time  = %s \n",s);
    return;
}


int main(void) {
	char str[] = "08:13:12PM";
	timeConversion(str);
	char str1[] = "08:13:12AM";
	timeConversion(str1);
	char str2[] = "12:00:00AM";
	timeConversion(str2);
	char str3[] = "12:00:00PM";
	timeConversion(str3);
	char str4[] = "11:13:12AM";
	timeConversion(str4);

	return 0 ;
}


/*
esatjar@seroiuts01946[16:24][home/esatjar/practice]$ ./a.out 
string  = 08:13:12PM 
extracteed am/pm  = PM   nh = 8 
calling func with PM , n h 8
nh = 20 
 convered time  = 20:13:12 
string  = 08:13:12AM 
extracteed am/pm  = AM   nh = 8 
convered time  = 08:13:12 
string  = 12:00:00AM 
extracteed am/pm  = AM   nh = 12 
convered time  = 00:00:00 
string  = 12:00:00PM 
extracteed am/pm  = PM   nh = 12 
calling func with PM , n h 12
nh = 24 
 convered time  = 24:00:00 
string  = 11:13:12AM 
extracteed am/pm  = AM   nh = 11 
convered time  = 11:13:12  */
