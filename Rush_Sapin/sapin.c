#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	my_display(int counter, char c)
{
  int	i;

  i = 0;
  while (i < counter)
    {
      write (1, &c, 1);
      i ++;
    }
}

int	my_base(int size)
{
  int	counter_s;
  int	counter_g;
  int	ground;
  int	counter_stars;
  int	stars;
  int	minus_stars;
  int	length;

  counter_s = 0;
  ground = 4;
  stars = 1;
  minus_stars = 0;
  length = 0;
  while (counter_s < size)
    {
      counter_g = 0;
      while (counter_g < ground)
	{
	  counter_stars = 0;
	  while (counter_stars < stars)
	    {
	      counter_stars ++;
	    }
	  counter_g ++;
	  stars = stars + 2;
	}
      ground ++;
      counter_s ++;
      minus_stars = (counter_s / 2) * 2;
      stars = ((stars - 2) - minus_stars);
      length = stars;
    }
  length = length + minus_stars;
  return (length);
}

void	my_trunk(int size)
{
  int	s_counter;
  int	trunk_counter;
  int	b_counter;
  int	blank;
  int	pipe;
  int	length;

  s_counter = 0;
  trunk_counter = 0;
  length = my_base(size);
  blank = ((length - size) / 2);
  pipe = (1 + ((size / 2) * 2));
  while (s_counter < size)
    {
      while (trunk_counter < size)
	{
	  trunk_counter ++;
	  b_counter = 0;
	  while (b_counter < blank)
	    {
	      write (1, " ", 1);
	      b_counter ++;
	    }
	  my_display(pipe, '|');
	  write (1, "\n", 1);
	  blank = blank --;
	}
      s_counter ++;
    }
  return ;
}

void	my_leaves(int size)
{
  int	counter_size;
  int	counter_floor;
  int	floor;
  int	space;
  int	star;
  int	length;
  int	withdrawal;

  counter_size = 0;
  floor = 4;
  star = 1;
  length = my_base(size);
  space = ((length -1) / 2);
  withdrawal = 0;  
  while (size <= 0)
    {
      return ;
    }
  while (counter_size < size)
    {
      counter_floor = 0;
      while ( counter_floor < floor)
	{
	  my_display(space, ' ');
	  my_display(star, '*');
	  write (1, "\n", 1);
	  counter_floor ++;
	  space = space - 1;
	  star = star + 2;
        }
       floor++;
       counter_size ++;
       withdrawal = (counter_size / 2) * 2;
       star = ((star - 2) - withdrawal);
       space = ((space + 1) + (withdrawal / 2));
    }
}

void	sapin(int size)
{
  my_leaves(size);
  my_trunk(size);
}

int main(int ac, char **av)
{
  sapin(atoi(av[1]));
  return 0;
}
