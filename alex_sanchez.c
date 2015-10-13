#include<linux/linkage.h>
#include<linux/time.h>
#include<linux/sched.h>

static int syears = 31536000 ;
static int smonth = 2628000 ;
static int sday = 86400 ;
static int shour = 3600 ;
static int smin = 60 ;

asmlinkage long sys_alex_sanchez(int pantherid)
{
  struct timeval t ;
  long time ;
  int years ;
  int months ;
  int days ;
  int hours ;
  int mins ;
  int sec ;

  do_gettimeofday(&t) ;

  time = t.tv_sec ;
  time = time - 849600 ;

  years = time / syears ;
  months = (time % syears) / smonth ;
  days = ((time % syears) % smonth) / sday ;
  hours = (((time % syears) % smonth) % sday) / shour ;
  mins = ((((time % syears) % smonth) % sday) % shour) / smin ;
  sec = ((((time % syears) % smonth) % sday) % shour) % smin ;

  printk("sys_alex_sanchez called from process %d with panther ID %d.\n", current->pid, pantherid) ;
  printk("%02d:%02d:%02d, %02d %02d, %d\n", hours, mins, sec, months + 1, days, years + 1970) ;

  return 0 ;

}
