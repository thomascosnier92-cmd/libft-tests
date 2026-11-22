#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main (void)
{
    char Char = 'W';
    char *String = "My name is Yoshikage Kira. I'm 33 years old. My house is in the northeast\nsection of Morioh, where all the villas are, and I am not married.\nI work as an employee for the Kame Yu department stores, and I get home\nevery day by 8 PM at the latest. I don't smoke, but I occasionally\ndrink. I'm in bed by 11 PM, and make sure I get eight hours of sleep,\nno matter what. After having a glass of warm milk and doing\nabout twenty minutes of stretches before going to bed, I usually have\nno problems sleeping until morning. Just like a baby,\nI wake up without any fatigue or stress in the morning.\nI was told there were no issues at my last check-up.\nI'm trying to explain that I'm a person who wishes to live a\nvery quiet life. I take care not to trouble myself with any enemies,\nlike winning and losing, that would cause me to lose sleep\nat night. That is how I deal with society, and I know\nthat is what brings me happiness. Although, if I were to\nfight I wouldn't lose to anyone. ";
    int Int = 3000;
    int Dec = 3000 / 55;
    void *Ptr;
    Ptr = &Int; 
    unsigned int Uns_Dec = 3000 / 55;
    int Lower = 98765;
    int Upper = 43210;

    printf("Original Printf :\n\n\n");
    printf("Char : %c\n\nPercentage : %%\n\nString : %s\n\nInteger : %i\n\nDecimal : %d\n\nPointer : %p\n\nUnsigned Decimal : %u\n\nNumber in base 16 lowercase : %x\n\nNumber in base 16 uppercase : %X\n\n", Char, String, Int, Dec, Ptr, Uns_Dec, Lower, Upper);
    printf("\n\n\n");

    ft_printf("My Printf Tests :\n\n\n\n");
	ft_printf("Char : %c\n\nPercentage : %%\n\nString : %s\n\nInteger : %i\n\nDecimal : %d\n\nPointer : %p\n\nUnsigned Decimal : %u\n\nNumber in base 16 lowercase : %x\n\nNumber in base 16 uppercase : %X\n\n", Char, String, Int, Dec, Ptr, Uns_Dec, Lower, Upper);
    ft_printf("\n\nTHE END THANK YOU FOR REVIEWING\n");
}
