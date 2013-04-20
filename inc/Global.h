// **************************************************************************
// Tianchi C++ library for Qt (open source)
// 天池共享源码库
// 版权所有 (C) 天池共享源码库开发组
// 授权协议：请阅读天池共享源码库附带的授权协议
// **************************************************************************
// 文档说明：常用功能函数
// ==========================================================================
// 开发日志：
// 日期         人员        说明
// --------------------------------------------------------------------------
// 2013.04.11   cnhemiya    建立
// 2013.04.17   XChinux     参照Qt/qglobal.h文件重写Global.h
// ==========================================================================
// 注意事项:
// 1. 编译Tianchi DLL时请在 .pro 中添加：
//      DEFINES += TIANCHI_EXPORT
// 2. 使用Tianchi DLL时请在.pro中添加
//      DEFINES += TIANCHI_IMPORT
// ==========================================================================

#ifndef TIANCHI_GLOBAL_H
#define TIANCHI_GLOBAL_H


/**
 * TIANCHI_NAMESPACE 应该在.pro中定义,但为了防止名字冲突,这里强制定义
 */
#ifndef TIANCHI_NAMESPACE
#   define TIANCHI Tianchi
#   define TIANCHI_NAMESPACE Tianchi
#else
#   define TIANCHI TIANCHI_NAMESPACE
#endif


#include <QtCore/qglobal.h>

#ifndef __cplusplus
#    error "Tianchi library only support C++ Compilers"
#endif


#define TIANCHI_VERSION_STR   "0.0.1"
/*
   TIANCHI_VERSION is (major << 16) + (minor << 8) + patch.
*/
#define TIANCHI_VERSION 0x000001
/*
   can be used like #if (TIANCHI_VERSION >= TIANCHI_VERSION_CHECK(4, 4, 0))
*/
#define TIANCHI_VERSION_CHECK(major, minor, patch) ((major<<16)|(minor<<8)|(patch))

#if !defined(TIANCHI_NAMESPACE) // user namespace, copy from qglobal.h

# define TIANCHI_PREPEND_NAMESPACE(name) ::name
# define TIANCHI_USE_NAMESPACE
# define TIANCHI_BEGIN_NAMESPACE
# define TIANCHI_END_NAMESPACE

#else /* user namespace */

# define TIANCHI_PREPEND_NAMESPACE(name) ::TIANCHI_NAMESPACE::name
# define TIANCHI_USE_NAMESPACE using namespace ::TIANCHI_NAMESPACE;
# define TIANCHI_BEGIN_NAMESPACE namespace TIANCHI_NAMESPACE {
# define TIANCHI_END_NAMESPACE }

namespace TIANCHI_NAMESPACE {}

#endif /* user namespace */


#define TIANCHI_BEGIN_HEADER
#define TIANCHI_END_HEADER

#if defined(TIANCHI_EXPORT)
#  define TIANCHI_API Q_DECL_EXPORT
#elif defined(TIANCHI_IMPORT)
#  define TIANCHI_API Q_DECL_IMPORT
#else
#  define TIANCHI_API
#endif


#endif // TIANCHI_GLOBAL_H
