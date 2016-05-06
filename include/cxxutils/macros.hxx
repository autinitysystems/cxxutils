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

/**
 *  \def CXXUTILS_WITH(decl)
 *
 *  \brief \a decl is a RAII object being destroyed after the following statement/scope.
 *
 *  This macro can be used with RAII objects that are only there for their side effects.
 */
#define CXXUTILS_WITH(decl) for (bool just_once = true; just_once;) for (decl; just_once; just_once = false)

#endif // CXXUTILS_MACROS_HXX
