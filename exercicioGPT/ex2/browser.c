#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "browser.h"
#include "stack.h"

struct _Browser
{
    Stack *backStack;
    Stack *forwardStack;
    char *currentPage;
};

/**
 * @brief Initializes the browser.
 *
 * @param browser A pointer to the Browser structure.
 * @param homePage The homepage URL to initialize the browser.
 */
Browser *initBrowser(char *homePage)
{
    Browser *browser = calloc(1, sizeof(Browser));
    browser->backStack = createStack();
    browser->forwardStack = createStack();
    browser->currentPage = strdup(homePage);
    return browser;
}

/**
 * @brief Visits a new webpage.
 *
 * Backup Current Page: If there's already a current page in the browser, it pushes that page onto the backStack. This is done to keep track of the browsing history.
 * Clear Forward Stack: It clears the forwardStack since visiting a new page invalidates any forward navigation history.
 * Update Current Page: It updates the current page of the browser to the newly visited URL.
 *
 * @param browser A pointer to the Browser structure.
 * @param url The URL of the new webpage to visit.
 */
void visitPage(Browser *browser, char *url)
{
    // Backup current page to backStack
    if (browser->currentPage)
    {
        push(browser->backStack, browser->currentPage);
    }

    // Clear forwardStack
    while (!isEmpty(browser->forwardStack))
    {
        free(pop(browser->forwardStack));
    }

    // Update current page
    browser->currentPage = strdup(url);
}

/**
 * @brief Navigates back to the previous page.
 *
 * Check if There's a Page to Go Back To: It checks if there are any pages in the backStack (i.e., if there's any browsing history).
 * Backup Current Page: If there's a page to go back to, it first pushes the current page onto the forwardStack, ensuring that forward navigation is still possible.
 * Update Current Page: It then updates the current page of the browser to the last visited page from the backStack
 *
 * @param browser A pointer to the Browser structure.
 */
void goBack(Browser *browser)
{
    // Check if there's a page to go back to
    if (!isEmpty(browser->backStack))
    {
        // Backup current page to forwardStack
        push(browser->forwardStack, browser->currentPage);
        // Update current page to the previous page
        browser->currentPage = pop(browser->backStack);
    }
    else
    {
        printf("No pages to go back to.\n");
    }
}

/**
 * @brief Navigates forward to the next page.
 *
 * Check if There's a Page to Go Forward To: It checks if there are any pages in the forwardStack (i.e., if there's any forward navigation history).
 * Backup Current Page: If there's a page to go forward to, it first pushes the current page onto the backStack, ensuring that backward navigation is still possible.
 * Update Current Page: It then updates the current page of the browser to the next visited page from the forwardStack.
 *
 * @param browser A pointer to the Browser structure.
 */
void goForward(Browser *browser)
{
    // Check if there's a page to go back to
    if (!isEmpty(browser->forwardStack))
    {
        push(browser->backStack, browser->currentPage);
        browser->currentPage = pop(browser->forwardStack);
    }
    else
    {
        printf("No pages to go forward to.\n");
    }
}

/**
 * @brief Prints the current page.
 *
 * @param browser A pointer to the Browser structure.
 */
void printCurrentPage(Browser *browser)
{
    printf("Current Page: %s\n", browser->currentPage);
}

/**
 * @brief Frees all resources used by the browser.
 *
 * @param browser A pointer to the Browser structure.
 */
void freeBrowser(Browser *browser)
{
    if (browser->currentPage)
    {
        free(browser->currentPage);
    }
    
    destroyStack(browser->forwardStack);
    destroyStack(browser->backStack);
    free(browser);
}
