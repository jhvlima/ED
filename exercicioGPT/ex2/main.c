/**
 * Exercicio proposto pelo chat gpt para implematar uma pilha pra simular um browser que pode:
 *  - visitar uma pagina
 *  - ir pra pagina anterior 
 *  - ir pra pagina seguinte
 * 
*/
#include <stdio.h>
#include "browser.h"

int main()
{
    Browser *browser = initBrowser("home.html");

    printCurrentPage(browser);

    visitPage(browser, "page1.html");
    printCurrentPage(browser);

    visitPage(browser, "page2.html");
    printCurrentPage(browser);

    goBack(browser);
    printCurrentPage(browser);

    goBack(browser);
    printCurrentPage(browser);

    goForward(browser);
    printCurrentPage(browser);

    visitPage(browser, "page3.html");
    printCurrentPage(browser);

    goBack(browser);
    printCurrentPage(browser);

    goForward(browser);
    printCurrentPage(browser);

    freeBrowser(browser);

    return 0;
}
