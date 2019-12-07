#pragma once

#include "CoreMinimal.h"

class FFlowAssetEditor;

class UEdGraph;
struct Rect;

class FLOWEDITOR_API FFlowGraphUtilities
{
public:
	static void PasteNodesHere(UEdGraph* Graph, const FVector2D& Location);
	static bool CanPasteNodes(const UEdGraph* Graph);

	/** Get the bounding area for the currently selected nodes
	 *
	 * @param Graph The Graph we are finding bounds for
	 * @param Rect Final output bounding area, including padding
	 * @param Padding An amount of padding to add to all sides of the bounds
	 *
	 * @return false if nothing is selected*/
	static bool GetBoundsForSelectedNodes(const UEdGraph* Graph, FSlateRect& Rect, float Padding = 0.0f);

	/** Gets the number of nodes that are currently selected */
	static int32 GetNumberOfSelectedNodes(const UEdGraph* Graph);

	/** Get the currently selected set of nodes */
	static TSet<UObject*> GetSelectedNodes(const UEdGraph* Graph);

private:
	/** Get IFlowAssetEditor for given object, if it exists */
	static TSharedPtr<FFlowAssetEditor> GetFlowAssetEditorForObject(const UObject* ObjectToFocusOn);

	FFlowGraphUtilities() {}
};