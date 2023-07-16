#pragma once
#include "DrawDebugHelpers.h"
#define DRAW_SPHERE(Location) if(GetWorld()) DrawDebugSphere(GetWorld(),Location,25.f,12,FColor::Cyan,true);
#define DRAW_SPHERE_FRAME(Location) if(GetWorld()) DrawDebugSphere(GetWorld(),Location,25.f,12,FColor::Cyan,false,-1.f);
#define DRAW_SPHERE_COLOR(Location,Color) if(GetWorld()) DrawDebugSphere(GetWorld(),Location,25.f,12,Color,true);
#define DRAW_CAPSULE(Location) if (GetWorld()) DrawDebugCircle(GetWorld(), FMatrix(), 200, 50, FColor(0,104,167), true, -1, 0, 10);
#define DRAW_LINE(StartLocation,EndLocation) if(GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Emerald, true, -1.f, 0, 1.F);
#define DRAW_LINE_FRAME(StartLocation,EndLocation) if(GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Emerald, false, -1.f, 0, 1.F);
#define DRAW_POINT(Location)  if(GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Blue, true);
#define DRAW_POINT_FRAME(Location)  if(GetWorld()) DrawDebugPoint(GetWorld(), Location, 15.f, FColor::Blue, false,-1.f);
#define DRAW_VECTOR(StartLocation,EndLocation) if (GetWorld()) \
{\
	DRAW_LINE(StartLocation,EndLocation)\
	DRAW_POINT(EndLocation)\
}

#define DRAW_VECTOR_FRAME(StartLocation,EndLocation) if (GetWorld()) \
{\
	DRAW_LINE_FRAME(StartLocation,EndLocation)\
	DRAW_POINT_FRAME(EndLocation)\
}