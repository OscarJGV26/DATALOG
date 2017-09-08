#pragma once
#include <signal.h>
#include <time.h>
#define CLOCKID CLOCK_REALTIME
#define SIG SIGRTMIN
volatile int execute=1;
long long freq_nanosecs;
timer_t timerid;
struct sigevent sev;
struct itimerspec its;
struct timespec real_time_clock;
sigset_t mask;
struct sigaction sa;
double rt_clock=0;
double timer=0;
double real_period=0;
