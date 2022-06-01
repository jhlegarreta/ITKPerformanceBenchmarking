/*=========================================================================
 *
 *  Copyright NumFOCUS
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         https://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#ifndef itkHighPriorityRealTimeClock_h
#define itkHighPriorityRealTimeClock_h

#include "itkRealTimeClock.h"
#include "PerformanceBenchmarkingExport.h"

#if defined(_WIN32)
#  include <windows.h>
#endif // defined(_WIN32)

namespace itk
{

/** \class HighPriorityRealTimeClock
 * \brief The HighPriorityRealTimeClock provides a timestamp from a real-time clock.
 *
 * It subclasses from RealTimeClock to bump the process priority.
 *
 * \ingroup PerformanceBenchmarking
 *
 */
class PerformanceBenchmarking_EXPORT HighPriorityRealTimeClock : public RealTimeClock
{
public:
  using Self = HighPriorityRealTimeClock;
  using Superclass = RealTimeClock;
  using Pointer = SmartPointer<Self>;
  using ConstPointer = SmartPointer<const Self>;

  /** Method for defining the name of the class */
  itkTypeMacro(HighPriorityRealTimeClock, RealTimeClock);

  /** Method for creation through the object factory */
  itkNewMacro(Self);

protected:
  /** Constructor */
  HighPriorityRealTimeClock();

  /** Destructor */
  ~HighPriorityRealTimeClock() override;

  /** Method for raising and restoring the priority */
  virtual void
  RaisePriority();
  virtual void
  RestorePriority();

private:
#if defined(_WIN32)
  DWORD m_OldPriorityClass;
  int   m_OldThreadPriority;
#else
  int m_OldProcessPriority;
#endif //  defined(_WIN32)

  void
  DisplayErrorMessage();
};

} // end of namespace itk

#endif // __itkHighPriorityRealTimeClock_h
