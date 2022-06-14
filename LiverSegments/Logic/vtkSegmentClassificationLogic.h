/*===============================================================================

  Project: LiverSegments
  Module: vtkSegmentClassificationLogic.h

  Copyright (c) 2019,  Oslo University Hospital

  All rights reserved. This is propietary software. In no event shall the author
  be liable for any claim or damages 

  ===============================================================================*/


#ifndef __vtkSegmentClassificationLogic_h
#define __vtkSegmentClassificationLogic_h

#include "vtkSlicerLiverSegmentsModuleLogicExport.h"

#include <vtkObject.h>
#include <vtkSmartPointer.h>

// Forward delcarations
class vtkPolyData;
class vtkMRMLLabelMapVolumeNode;
class vtkSegment;
class vtkMRMLSegmentationNode;


// Class vtkSegmentClassificationLogic
class VTK_SLICER_LIVERSEGMENTS_MODULE_LOGIC_EXPORT
vtkSegmentClassificationLogic : public vtkObject
{
 private:
    vtkSmartPointer<vtkPolyData> centerlineModel;

 public:
  static vtkSegmentClassificationLogic *New();
  vtkTypeMacro(vtkSegmentClassificationLogic, vtkObject);
  void PrintSelf(ostream& os, vtkIndent indent) override;

 public:
  void SegmentClassification(vtkPolyData *centerlines,
                             vtkMRMLLabelMapVolumeNode *labelMap);
  void addSegmentToCenterlineModel(vtkSmartPointer<vtkPolyData> segment);
  void BuildCenterlineSearchModel();
  int SegmentClassificationProcessing(/*vtkPolyData *centerlineModel, */vtkMRMLLabelMapVolumeNode *labelMap);

 protected:
  vtkSegmentClassificationLogic();
  ~vtkSegmentClassificationLogic() override;
  vtkSegmentClassificationLogic(const vtkSegmentClassificationLogic&);
  void operator=(const vtkSegmentClassificationLogic&);

};

#endif

