import { useState, useEffect } from "react";
import "./MovingDotOnCanvas.css";
import { Stage, Layer, Rect, Circle } from "react-konva";

function MovingDotOnCanvas() {
  const [xCoordinate, SetXCoordinate] = useState(30);

  useEffect(() => {
    const interval = setInterval(() => {
      SetXCoordinate(xCoordinate + 1);
    }, 75);

    return () => clearInterval(interval);
  }, [xCoordinate]);

  return (
    <>
      <Stage width={window.innerWidth} height={window.innerHeight}>
        <Layer>
          <Circle
            x={xCoordinate}
            y={50}
            stroke="black"
            radius={25}
            fill="black"
          />
        </Layer>
      </Stage>
    </>
  );
}

export default MovingDotOnCanvas;
