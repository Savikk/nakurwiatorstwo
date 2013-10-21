/*
 * Maciej Małecki
 * sm__time_stop16@gmail.com
 */
#include "lib.h"

Time *new_time(void) {
  Time *p = MALLOC(Time, 1);
  p->time = 0;
  return p;
}

void start_time(Time *t) {
  clock_gettime(CLOCK_REALTIME, &(t->start));
}

void stop_time(Time *t) {
  clock_gettime(CLOCK_REALTIME, &(t->stop));
  t->time += time_diff(&(t->stop), &(t->start));
}

double time_diff(TimeSpec *p, TimeSpec *q) {
  return ((p->tv_sec * MLD) + p->tv_nsec) - ((q->tv_sec * MLD) + q->tv_nsec);
}

void print_time(Time *t) {
  printf("\nTime:\t%0.16lf\n", (double) t->time / MLD);
}

double get_time(Time *t) {
  return (double) t->time / MLD;
}

void delete_time(Time *t) {
  free(t);
}
