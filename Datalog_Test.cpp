#include "DATALOG.h"
#include "Timing.h"
#include <unistd.h>
#include <math.h>
DATALOG datalog;
int main(int argc, char *argv[]){
    datalog.begin();
    double amplitude,frequency,sampling_time, Time;
    sscanf(argv[1],"%lf",&amplitude);
    sscanf(argv[2],"%lf",&frequency);
    sscanf(argv[3],"%lf",&sampling_time);
    sscanf(argv[4],"%lf",&Time);
    timer_begin(sampling_time);
    long iterations= (long) Time/sampling_time;
    double test_signal;
    double pi=3.141592653;
    double omega=frequency*2*pi;
    float array[10];
    int count=0;
    double sampling_time_precision=0.001;  
    for(long i=0;i<iterations;i++){
        while(execute==0);
        test_signal=amplitude*sin(omega*i*sampling_time);
        for(int j=0;j<10;j++){
            array[j]=(float)test_signal;
        }
        array[0]=real_period;
        array[1]=real_period-sampling_time;
        if(array[1]>sampling_time_precision||array[1]<-sampling_time_precision){
            printf("Real Period is %10.10f\n",real_period);
            count++;
        }
        datalog.write(array,array,array,array,array,array,array,array,array);
        printf("Writing...\n");
        sleep(1);
    }
    for(int i=0;i<100;i++)datalog.close();
    count-=2;
    printf("The system recorded %d violations of the required sampling time\n", count);
    printf("Program Terminated.\n");
}
