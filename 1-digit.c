#include "main.h"

/**
 * init_params - Initializes parameters struct and resets buffer
 * @p: Pointer to the parameters struct
 * @arg_list: The argument pointer
 *
 * Return: void
 */

void init_p(parameters_t *p, va_list arg_list)
{
    p->unsign = 0;
    p->plus_f = 0;
    p->space_f = 0;
    p->hashtag_f = 0;
    p->zero_f = 0;
    p->minus_f = 0;
    p->width = 0;
    p->prec = UINT_MAX;
    p->h_mod = 0;
    p->l_mod = 0;
    (void)arg_list;
}
