/*
    This is main.c file.  It contains the main() function for the Consultation problem.
	
	DO the following to test your CONSULT-LASTNAME.c solution: 
	
	1. Edit Line 38 below to include your own source file.
	2. Compile this main.c file to produce main.exe.  Make sure to use -Wall -std=c99 compiler directive!
	3. If there are no compilation errors and/or warnings, go to the Command Line Interface via CMD. 
	4. Run main.exe in the command line with I/O redirection as follows:
   
        for Windows :  main < SAMPLE-IN.txt > ACTUAL-LASTNAME.txt           	
        for Mac OS X:  ./main < SAMPLE-IN.txt > ACTUAL-LASTNAME.txt

	   where SAMPLE-IN.txt is an accompanying sample text files that contain input data 
	   read via scanf().

       For example, if your lastname is SANTOS, you should run main.exe as:
	   
       	for Windows :   main < SAMPLE-IN.txt > ACTUAL-SANTOS.txt
		for Mac OS X:   ./main < SAMPLE-IN.txt > ACTUAL-SANTOS.txt
		      
    5. Using Notepad (or other text editors), open and compare your ACTUAL-LASTNAME.txt with the 
	   contents of the accompanying EXPECTED.TXT file. They should be exactly the same -- even the spacing!
	   If they are not the same, then there's a strong probability that there's a logical error in your 
	   solution, or you did not follow some specifications.  

	6. Debug and retry until you get the correct results.    
	   
	7. Devise your own tests. Do NOT simply depend on the sample INPUT and EXPECTED text files.
*/

/* Do NOT change  the #include below.  You are NOT allowed to include other files. */

/*
    TO DO: change the #include below to your own file/solution. For example if your 
	lastname is SANTOS, then it should be changed to #include "Consult-SANTOS.c".
*/	
#include "Consult-LASTNAME.c"

/*
    This is the main() function for testing your solution.  
	
	You are not supposed to modify the contents and the logic of this function.
    
    If you need to experiment, i.e. you'd like to edit/introduce new codes, then it is suggested that you
	copy this file, and make changes on your copy.
	
	Note that the teacher-in-charge of checking your solution may use another set of input data 
	and a different main() function.  
	
	Your functions should work correctly even with a different set of input data and a different main() function.
*/	

int
main()
{
   doctorType drDirectory[MAX_DOCS], 
              docsToday[MAX_DOCS];
   int numDoctors = 0, curDocs;
   int i;
   doctorType * pRecoDoc;
   
   /* Testing inputDoctor() */
   printf("---Testing inputDoctor()---\n");
   printf("Get inputs:\n");
   while (numDoctors < MAX_DOCS &&
          inputDoctor(&drDirectory[numDoctors]))
      numDoctors++;
   
   printf("Number of input doctors = %d\n\n", numDoctors);
   for (i = 0; i < numDoctors; i++)
      displayDoctor(drDirectory[i]);
  
   /* Testing genDoctorsToday(), assuming Wednesday */
   printf("\n\n---Testing genDoctorsToday()---\n");
   genDoctorsToday(drDirectory, numDoctors, 3, docsToday, &curDocs); 
   
   printf("Number of doctors on Wednesday = %d\n\n", curDocs);
   for (i = 0; i < curDocs; i++)
      displayDoctor(docsToday[i]);

   /* Testing trimList() */
   printf("\n\n---Testing trimList()---\n");
   trimList(drDirectory, &numDoctors);
   
   printf("\nAfter removing doctors with no clinic hours the whole week:\n");
   printf("Number of doctors left = %d\n", numDoctors);
   for (i = 0; i < numDoctors; i++)
      displayDoctor(drDirectory[i]);
  
   /* Testing sortAvail() */
   printf("\n\n---Testing sortAvail()---\n");
   sortAvail(docsToday, curDocs, 3);
   
   printf("\nAfter sorting based on Wednesday sched:\n");
   for (i = 0; i < curDocs; i++)
      displayDoctor(docsToday[i]);
  
   /* Testing reco() */
   printf("\n\n---Testing reco()---\n");
   pRecoDoc = reco(docsToday, curDocs, 1, "Pediatrics");
   
   printf("\n%s %s\n", "Looking for 1st available doctor whose",
          "specialization includes Pediatrics this Monday");
   if (pRecoDoc != NULL)
	   displayDoctor(*pRecoDoc);
   else printf("No doctor today\n");
     	  
   return 0;
}