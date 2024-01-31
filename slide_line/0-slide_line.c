#include "slide_line.h"

/**
 * slide_line - slide an array of integers
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 or 0
 */
int slide_line(int *line, size_t size, int direction)
{
    int current = 0, destination = 0;

    if (size < 1 || (direction != SLIDE_RIGHT && direction != SLIDE_LEFT))
        return 0;

    if (direction == SLIDE_RIGHT)
    {
        destination = (size - 1);
        for (current = (size - 2); current >= 0; current--)
        {
            if (line[current] == line[destination] && line[current])
                perform_slide(line, current, destination--);
            else if (line[current] != line[destination] && line[current])
            {
                if (line[destination] != 0)
                    destination--;
                if (line[destination] == 0)
                    perform_slide(line, current, destination);
            }
        }
    }
    else if (direction == SLIDE_LEFT)
    {
        for (current = 1; current < (int)size; current++)
        {
            if (line[current] == line[destination] && line[current])
                perform_slide(line, current, destination++);
            else if (line[current] != line[destination] && line[current])
            {
                if (line[destination] != 0)
                    destination++;
                if (line[destination] == 0)
                    perform_slide(line, current, destination);
            }
        }
    }
    return 1;
}

/**
 * perform_slide - merge the elements in the array
 * @line: Pointer to array
 * @current: index to slide and merge
 * @destination: index to merge into
 */
void perform_slide(int *line, int current, int destination)
{
    line[destination] += line[current];
    line[current] = 0;
}
