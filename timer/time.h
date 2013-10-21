/*
 * Maciej Małecki
 * smt116@gmail.com
 */
#ifndef SMT__LOCAL_TIME_LIB
#define SMT__LOCAL_TIME_LIB

  #include <time.h>

  #define MLD 1000000000.0

  typedef struct timespec TimeSpec;
  typedef struct Time {
    TimeSpec start;
    TimeSpec stop;
    unsigned long time;
  } Time;

  Time *new_time(void);
  void start_time(Time *);
  void stop_time(Time *);
  double time_diff(TimeSpec *, TimeSpec *);
  double get_time(Time *);
  void print_time(Time *);
  void delete_time(Time *);

#endif
