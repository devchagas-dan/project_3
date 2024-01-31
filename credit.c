#include <cs50.h>
#include <stdio.h>
#include <math.h> // biblioteca para poder utilizar potencia - função pow = power = potenciação

int every_other_digit (long credit_card); // nunca se esqueça de declarar o protótipo de uma função
int multiplyandsum (int last_digit); // outra função criada para  multiplicar os digitos
int number_of_digits (long credit_card);
bool isvalidAmex (long credit_card, int numbdig);
bool isvalidMaster (long credit_card, int numbdig);
bool isvalidVisa (long credit_card, int numbdig);

int main(void)
{
    long credit_card = get_long ("Credit Card number: ");
    // preciso chamar a função que eu criei colocando-a em uma nova função int e colocando o número do cartão de crédito como parâmetro
    int sum_every_other_digit = every_other_digit (credit_card);
    int numbdig = number_of_digits (credit_card);
    bool amex = isvalidAmex (credit_card, numbdig);
    bool master = isvalidMaster (credit_card, numbdig);
    bool visa = isvalidVisa (credit_card, numbdig);
    if (sum_every_other_digit % 10 != 0)
    {
        printf ("INVALID\n");
        return 0;
    }
    else if (amex == true)
    {
        printf ("AMEX\n");
    }
    else if (master == true)
    {
        printf ("MASTERCARD\n");
    }
    else if (visa == true)
    {
        printf ("VISA\n");
    }
    else
    {
        printf ("INVALID\n");
        return 0;
    }
}
//criar uma função bool para dizer se o cartão American express seria válido. Receberá dois argumentos, long do credti card e o int com os numeros dos digitos
bool isvalidAmex (long credit_card, int numbdig)
{
    //precisamos pegar agora os dois primeiros digitos do nosso cartão de credito
    int first_two_digits = credit_card / pow (10, 13);
    if((numbdig == 15) && (first_two_digits == 34 || first_two_digits == 37))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isvalidMaster (long credit_card, int numbdig)
{
    //precisamos pegar agora os dois primeiros digitos do nosso cartão de credito
    int first_two_digits = credit_card / pow (10, 14);
    if((numbdig == 16) && (first_two_digits > 50 && first_two_digits < 56)) // como fazer range de números em C
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isvalidVisa (long credit_card, int numbdig)
{
    if (numbdig == 13)
    {
        int first_digit = credit_card / pow (10 , 12);
        if (first_digit == 4)
        {
            return true;
        }
    }
    else if (numbdig == 16)
    {
        int first_digit = credit_card / pow (10 , 15);
        if (first_digit == 4)
        {
            return true;
        }

    }
    return false;

}

// agora preciso criar uma função que vai calcular o número de dígitos que o usuário inseriu
int number_of_digits (long credit_card)
{
    int count = 0;
    while (credit_card > 0)
    {
        count = count + 1;
        credit_card = credit_card / 10;
    }
    return count;

}

// criar uma função int que irá receber como parâmetro um long que é nosso número do cartão de credito
int every_other_digit (long credit_card)
{
    int sum = 0; // variável que será usada para somar todos os digitos alternadamente
    // criar uma função bool para que possamos alternaar os números
    bool IsAlternateDigit = false;
    while ( credit_card > 0)
    { // loop criado para somar ou dividir os números
    // só iremos excutar o código a seguir se nosso alternate for igual a true, para isso é preciso criar um função if
        if (IsAlternateDigit == true)
        {
        int last_digit = credit_card % 10; // isso nos dará o último digito pois vai dividir os número do cartão de crédito por 10 e nos dar o resto
        int product = multiplyandsum (last_digit); // agora o codigo deixará de somar e passará a multiplicar os numeros inseridos
        sum = sum + product; // com essa linha de código vamos pegar a soma somente dos números que nós queremos
        }
        else // era só criar um else para este if que conseguiriamos fazer a lógica abaixo
        {
            int last_digit = credit_card % 10;
            sum = sum + last_digit;
        }
        // precisamos criar uma lógica reversa para poder alternar os valores usando o símobolo !
        IsAlternateDigit = !IsAlternateDigit;
        // vamor criar uma lógica para remover o último dígito que foi encontrado
        credit_card = credit_card / 10;
    }
    return sum;

}

// criar uma nova função cujo propósito é multiplicar os digitos por 2
int multiplyandsum (int last_digit) // protótipo da função foi salvo no topo do código
// vamos receber o último dígito e multiplicá-lo por 2
{    int multiply = last_digit * 2; // preciso criar uma função do tipo int para multiplicar digitos por 2
    int sum = 0; // a variável do tipo int para usar para apoiar o loop while
    // precisamos verificar se o número contém 2 dígitos. Para fazer isso podemos usar um loop while para sempre somar os números
    while ( multiply > 0)
    {
        int last_digit_multiply = multiply % 10; // vamos achar o remainder com essa função. Do ultimo pro primeiro digito
        sum = sum + last_digit_multiply;
        multiply = multiply / 10;

    }
    return sum;
}


