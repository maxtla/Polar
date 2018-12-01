#pragma once

#ifdef _DEBUG
	#define _CRTDBG_MAP_ALLOC  
	#include <stdlib.h>  
	#include <crtdbg.h>
	#include "Log.h"
#endif

#ifdef _DEBUG
	#define PL_NEW		new(_NORMAL_BLOCK, __FILE__, __LINE__)
	//In case I somehow forget that I should be using PL_NEW (Defeats the purpose of PL_NEW tho)
	#define new				new(_NORMAL_BLOCK, __FILE__, __LINE__)
#else
	#define PL_NEW new
#endif // _DEBUG

namespace Polar
{
	namespace MLD
	{
#ifdef _DEBUG
		struct MemDiff
		{
			_CrtMemState _start = {};
			_CrtMemState _end = {};
			_CrtMemState _result = {};
		};

		static MemDiff _snapshotData = {};

		static _CrtMemState & InitialMemoryState()
		{
			static bool initialized = false;
			static _CrtMemState initialState = {};
			if (!initialized)
			{
				_CrtMemCheckpoint(&initialState);
				initialized = true;
			}
			return initialState;
		}

		static void OutputInitialMemoryState()
		{
			OutputDebugStringA("---------- Initial Memory State ----------\n");
			_CrtMemDumpStatistics(&InitialMemoryState());
			OutputDebugStringA("--------------------------------------------\n");
		}

		static void GetCurrentMemDiffSinceInit()
		{
			_CrtMemState currentState = {};
			_CrtMemState resultState = {};

			_CrtMemCheckpoint(&currentState);

			if (_CrtMemDifference(&resultState, &InitialMemoryState(), &currentState))
			{
				OutputDebugStringA("---------- Memory Difference Since Initialization ----------\n");
				_CrtMemDumpStatistics(&resultState);
				OutputDebugStringA("---------------------------------------------------------------\n");
			}
			else
				PL_CORE_ERROR(std::string(__func__) + ": Failed to Dump Memory Statistics");
		}

		static void SnapshotMemoryBegin()
		{
			_CrtMemCheckpoint(&_snapshotData._start);
		}

		static void SnapshotMemoryEnd()
		{
			_CrtMemCheckpoint(&_snapshotData._end);

			_CrtMemState resultState = {};

			if (_CrtMemDifference(&_snapshotData._result, &_snapshotData._start, &_snapshotData._end))
			{
				OutputDebugStringA("---------- Memory Difference For This Region----------\n");
				_CrtMemDumpStatistics(&_snapshotData._result);
				OutputDebugStringA("------------------------------------------------------------\n");
			}
			else
				PL_CORE_ERROR(std::string(__func__) + ": Failed to Dump Memory Statistics");
		}
		//Beware that calling this before Main has exited will show False Positives on any Static objects
		static void MemDumpAllSinceInit()
		{
			_CrtMemDumpAllObjectsSince(&InitialMemoryState());
		}
		//Beware that calling this before Main has exited will show False Positives on any Static objects
		static void MemDumpLatestSnapshotRegion()
		{
			_CrtMemDumpAllObjectsSince(&_snapshotData._result);
		}

#endif

		static void Init()
		{
#ifdef _DEBUG
			_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
			_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
			auto  initialState = InitialMemoryState();
#endif
		}

		//Beware that calling this before Main has exited will show False Positives on any Static objects
		static void Flush()
		{
#ifdef _DEBUG
			_CrtDumpMemoryLeaks();
#endif
		}
	}
}

#ifdef _DEBUG

	#define OutputInitialMemState						::Polar::MLD::OutputInitialMemoryState()
	#define MemDiffSinceInit								::Polar::MLD::GetCurrentMemDiffSinceInit()
	#define MemSnapshotBegin							::Polar::MLD::SnapshotMemoryBegin()
	#define MemSnapshotEnd								::Polar::MLD::SnapshotMemoryEnd()
	//Beware that calling this before Main has exited will show False Positives on any Static objects
	#define MemDumpLatestSnapshotRegion		::Polar::MLD::MemDumpLatestSnapshotRegion()
	//Beware that calling this before Main has exited will show False Positives on any Static objects
	#define MemDumpAllSinceInit						::Polar::MLD::MemDumpAllSinceInit()

#else
	#define OutputInitialMemState
	#define MemDiffSinceInit
	#define MemSnapshotBegin
	#define MemSnapshotEnd
	#define MemDumpLatestSnapshotRegion	
	#define MemDumpAllSinceInit	
#endif // _DEBUG

