/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#pragma once

#include <cinttypes>
#include <immintrin.h>

void MsgErr(const char* fmt, ...);

void MsgWarn(const char* fmt, ...);

static inline uint32_t swapU32(void const* pMem)
{
#ifdef WIN32
	//using immintrinsics
	return _load_be_u32(pMem);
#else 
	return *reinterpret_cast<const uint32_t*>(pMem);
#endif
}

static inline uint16_t swapU16(void const* pMem)
{
#ifdef WIN32
	//using immintrinsics
	return _load_be_u16(pMem);
#else 
	return *reinterpret_cast<const uint16_t*>(pMem);
#endif
}

static inline std::uint64_t swapU64(std::uint64_t value)
{
#ifdef WIN32
	return ((value & 0x00000000000000FF) << 56)
		| ((value & 0x000000000000FF00) << 40)
		| ((value & 0x0000000000FF0000) << 24)
		| ((value & 0x00000000FF000000) << 8)
		| ((value & 0x000000FF00000000) >> 8)
		| ((value & 0x0000FF0000000000) >> 24)
		| ((value & 0x00FF000000000000) >> 40)
		| ((value & 0xFF00000000000000) >> 56);
#else
	return value;
#endif
}

template <typename T>
inline T ToOffsetPtr(std::uint32_t offset, void* basePtr)
{
	const uintptr_t base = reinterpret_cast<uintptr_t>(basePtr);
	//const uintptr_t offsetPtr = reinterpret_cast<uintptr_t>(offset);
	return reinterpret_cast<T>(base + offset);
}