#ifndef SRC_EXPOSER_HPP
#define SRC_EXPOSER_HPP

namespace exposer {

template <class MemberType> struct Exposer {
  static MemberType memberPtr;
};
template <class MemberType> MemberType Exposer<MemberType>::memberPtr;

template <class MemberType, MemberType MemberPtr> struct ExposerImpl {
  static struct ExposerFactory {
    ExposerFactory() { Exposer<MemberType>::memberPtr = MemberPtr; }
  } factory;
};
template <class MemberType, MemberType Ptr>
typename ExposerImpl<MemberType, Ptr>::ExposerFactory
    ExposerImpl<MemberType, Ptr>::factory;

} // namespace exposer

#define ACCESS(ClassName, AttrName, AttrType)                                  \
  template struct exposer::ExposerImpl<decltype(&ClassName::AttrName),         \
                                       &ClassName::AttrName>;                  \
  AttrType &get_##AttrName##_from_##ClassName(ClassName &T) {                  \
    return T.*exposer::Exposer<AttrType ClassName::*>::memberPtr;              \
  }

#endif /* SRC_EXPOSER_HPP */
