#include "omp_testsuite.h"


	int result;
	int nr_iterations;
    

/* Declaration of the functions containing the code for the orphan regions */
#include <stdio.h>


/* End of declaration */


#include "omp_testsuite.h"

int j;
#pragma omp threadprivate(j)

int orph_test_omp_single_copyprivate(FILE * logFile)                                   
{
    

    result = 0;
    nr_iterations = 0;
#pragma omp parallel
    {
	
	    int i;
            for (i = 0; i < LOOPCOUNT; i++)
	    {
		/*
		   int thread;
		   thread = omp_get_thread_num ();
		 */
#pragma omp single copyprivate(j)
		{
		    nr_iterations++;
		    j = i;
		    /*printf ("thread %d assigns, j = %d, i = %d\n", thread, j, i);*/
		}
		/*	#pragma omp barrier*/
#pragma omp critical
		{
		    /*printf ("thread = %d, j = %d, i = %d\n", thread, j, i);*/
		    result = result + j - i;
		}
#pragma omp barrier
	    } /* end of for */
	
    } /* end of parallel */
    return ((result == 0) && (nr_iterations == LOOPCOUNT));
}
int main()
{
	int i;			/* Loop index */
	int result;		/* return value of the program */
	int failed=0; 		/* Number of failed tests */
	int success=0;		/* number of succeeded tests */
	static FILE * logFile;	/* pointer onto the logfile */
	static const char * logFileName = "bin/c/orph_test_omp_single_copyprivate.log";	/* name of the logfile */


	/* Open a new Logfile or overwrite the existing one. */
	logFile = fopen(logFileName,"w+");

	printf("######## OpenMP Validation Suite V %s ######\n", OMPTS_VERSION );
	printf("## Repetitions: %3d                       ####\n",REPETITIONS);
	printf("## Loop Count : %6d                    ####\n",LOOPCOUNT);
	printf("##############################################\n");
	printf("Testing omp single copyprivate\n\n");

	fprintf(logFile,"######## OpenMP Validation Suite V %s ######\n", OMPTS_VERSION );
	fprintf(logFile,"## Repetitions: %3d                       ####\n",REPETITIONS);
	fprintf(logFile,"## Loop Count : %6d                    ####\n",LOOPCOUNT);
	fprintf(logFile,"##############################################\n");
	fprintf(logFile,"Testing omp single copyprivate\n\n");

	for ( i = 0; i < REPETITIONS; i++ ) {
		fprintf (logFile, "\n\n%d. run of orph_test_omp_single_copyprivate out of %d\n\n",i+1,REPETITIONS);
		if(orph_test_omp_single_copyprivate(logFile)){
			fprintf(logFile,"Test successful.\n");
			success++;
		}
		else {
			fprintf(logFile,"Error: Test failed.\n");
			printf("Error: Test failed.\n");
			failed++;
		}
	}

    if(failed==0){
		fprintf(logFile,"\nDirective worked without errors.\n");
		printf("Directive worked without errors.\n");
		result=0;
	}
	else{
		fprintf(logFile,"\nDirective failed the test %i times out of %i. %i were successful\n",failed,REPETITIONS,success);
		printf("Directive failed the test %i times out of %i.\n%i test(s) were successful\n",failed,REPETITIONS,success);
		result = (int) (((double) failed / (double) REPETITIONS ) * 100 );
	}
	printf ("Result: %i\n", result);
	return result;
}

/* Automatically generated definitions of the orphan functions */

void orph1_omp_single_copyprivate (FILE * logFile) {
	    int i;
            for (i = 0; i < LOOPCOUNT; i++)
	    {
		/*
		   int thread;
		   thread = omp_get_thread_num ();
		 */
#pragma omp single copyprivate(j)
		{
		    nr_iterations++;
		    j = i;
		    /*printf ("thread %d assigns, j = %d, i = %d\n", thread, j, i);*/
		}
		/*	#pragma omp barrier*/
#pragma omp critical
		{
		    /*printf ("thread = %d, j = %d, i = %d\n", thread, j, i);*/
		    result = result + j - i;
		}
#pragma omp barrier
	    } /* end of for */
	
}
/* End of automatically generated definitions */