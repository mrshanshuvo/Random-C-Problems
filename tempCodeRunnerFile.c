printf("\nDecoded message is: ");
    mul(inv_key, result, decode);
    for (i = 0; i < 10; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            if ( ((decode[j][i]+96)) >= 97 && ((decode[j][i]+96) <= 123))
                printf("%c", (decode[j][i] + 96) );
            else if ( decode[j][i] == 32)
                printf(" ");
        }
    }