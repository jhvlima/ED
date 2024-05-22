#ifndef BROWSER_H
#define BROWSER_H

#include "stack.h"

typedef struct _Browser Browser;

/**
 * @brief Initializes the browser.
 *
 * @param browser A pointer to the Browser structure.
 * @param homePage The homepage URL to initialize the browser.
 */
Browser *initBrowser(char *homePage);

/**
 * @brief Visits a new webpage.
 *
 * @param browser A pointer to the Browser structure.
 * @param url The URL of the new webpage to visit.
 */
void visitPage(Browser *browser, char *url);

/**
 * @brief Navigates back to the previous page.
 *
 * @param browser A pointer to the Browser structure.
 */
void goBack(Browser *browser);

/**
 * @brief Navigates forward to the next page.
 *
 * @param browser A pointer to the Browser structure.
 */
void goForward(Browser *browser);

/**
 * @brief Prints the current page.
 *
 * @param browser A pointer to the Browser structure.
 */
void printCurrentPage(Browser *browser);

/**
 * @brief Frees all resources used by the browser.
 *
 * @param browser A pointer to the Browser structure.
 */
void freeBrowser(Browser *browser);

#endif // BROWSER_H
