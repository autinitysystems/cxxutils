/*************************************************
 * Copyright © 2015, afr-consulting GmbH         *
 *                                               *
 * See the file COPYING for copying permissions. *
 *************************************************/

#ifndef CXXUTILS_MACROS_HXX
#define CXXUTILS_MACROS_HXX

/**
 *  \file macros.hxx
 *
 *  \brief Useful macros for everday use.
 *
 *  This header contains several useful macros which did not fit in any of the other headers.
 */

/**
 *  \def CXXUTILS_UNUSED(x)
 *
 *  \brief Mark variable \a x as unused.
 *
 *  This macro explicitely says that the developer is aware of the variable \a x being unused and that this is intended.
 */
#define CXXUTILS_UNUSED(x) ((void)x)

#endif // CXXUTILS_MACROS_HXX
