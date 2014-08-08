#ifndef CXXUTILS_NONE_HXX
#define CXXUTILS_NONE_HXX

/**
 *  \file none.hxx
 *
 *  \brief Utility class to default-construct objects of classes with lengthy names.
 *
 *  This file contains the \a none object of an anonymous class.
 *  It can be used e.g. in return statements to return a default-constructed
 *  object of a class with a lengthy name.
 */

namespace cxxutils
{
    static struct
    {
        template <typename Target>
        operator Target () const
        {
            return Target();
        }
    } const none; ///< Nice helper to default-construct objects of classes with lengthy names.
}

#endif // CXXUTILS_NONE_HXX
