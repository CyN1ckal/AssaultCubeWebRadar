import { useEffect, useState } from "react";
import { Stage, Layer, Rect, Circle } from "react-konva";

let JsonString =
  '{"playerlist":{"PlayerNumber0":{"x":"154.895203","y":"40.539955","yaw":"220.090881","pitch":"-12.353676","teamID":"1"},"PlayerNumber1":{"x":"125.131294","y":"50.892475","yaw":"340.511566","pitch":"-1.306888","teamID":"1"},"PlayerNumber2":{"x":"178.537048","y":"92.181297","yaw":"50.485046","pitch":"-1.542923","teamID":"1"},"PlayerNumber3":{"x":"146.510559","y":"39.614437","yaw":"151.550171","pitch":"-1.708732","teamID":"1"},"PlayerNumber4":{"x":"118.672836","y":"76.501709","yaw":"223.877289","pitch":"0.000000","teamID":"1"},"PlayerNumber5":{"x":"197.510193","y":"92.956230","yaw":"56.449280","pitch":"0.000000","teamID":"1"},"PlayerNumber6":{"x":"137.056274","y":"56.834930","yaw":"150.630814","pitch":"-1.569455","teamID":"1"},"PlayerNumber7":{"x":"152.694611","y":"41.784630","yaw":"124.041710","pitch":"-1.275064","teamID":"1"},"PlayerNumber8":{"x":"121.820839","y":"36.549217","yaw":"212.044922","pitch":"-1.255005","teamID":"1"},"PlayerNumber9":{"x":"142.741745","y":"51.912502","yaw":"340.120209","pitch":"-1.718902","teamID":"1"},"PlayerNumber10":{"x":"129.376999","y":"46.834614","yaw":"323.155975","pitch":"-1.529513","teamID":"1"},"PlayerNumber11":{"x":"151.776627","y":"52.906284","yaw":"84.905632","pitch":"-1.694589","teamID":"1"},"PlayerNumber12":{"x":"148.785645","y":"46.032898","yaw":"300.718628","pitch":"-1.654317","teamID":"1"},"PlayerNumber13":{"x":"146.474121","y":"43.988651","yaw":"352.899719","pitch":"-1.736942","teamID":"1"},"PlayerNumber14":{"x":"116.767082","y":"58.233124","yaw":"345.765503","pitch":"-1.509355","teamID":"1"},"PlayerNumber15":{"x":"146.474869","y":"41.779861","yaw":"111.439774","pitch":"-0.000000","teamID":"1"},"PlayerNumber16":{"x":"177.578812","y":"187.364090","yaw":"154.816940","pitch":"0.000000","teamID":"0"},"PlayerNumber17":{"x":"117.193321","y":"197.118195","yaw":"43.100677","pitch":"0.000000","teamID":"0"},"PlayerNumber18":{"x":"167.446869","y":"170.100586","yaw":"298.226257","pitch":"-1.237986","teamID":"0"},"PlayerNumber19":{"x":"165.843765","y":"150.448090","yaw":"312.441132","pitch":"-1.431911","teamID":"0"},"PlayerNumber20":{"x":"149.842178","y":"193.847061","yaw":"116.264679","pitch":"0.000000","teamID":"0"},"PlayerNumber21":{"x":"125.345207","y":"209.870102","yaw":"161.501343","pitch":"0.000000","teamID":"0"},"PlayerNumber22":{"x":"140.309311","y":"198.100021","yaw":"87.290985","pitch":"0.000000","teamID":"0"},"PlayerNumber23":{"x":"175.870255","y":"185.131744","yaw":"181.779221","pitch":"0.000000","teamID":"0"},"PlayerNumber24":{"x":"174.683243","y":"192.328415","yaw":"177.531982","pitch":"0.000000","teamID":"0"},"PlayerNumber25":{"x":"114.983879","y":"197.725830","yaw":"81.578621","pitch":"0.000000","teamID":"0"},"PlayerNumber26":{"x":"165.784134","y":"173.839645","yaw":"318.978699","pitch":"-1.057864","teamID":"0"},"PlayerNumber27":{"x":"179.877014","y":"188.369049","yaw":"187.747925","pitch":"0.000000","teamID":"0"},"PlayerNumber28":{"x":"175.858795","y":"194.772903","yaw":"62.974335","pitch":"0.000000","teamID":"0"},"PlayerNumber29":{"x":"163.682419","y":"201.302048","yaw":"0.926551","pitch":"2.808477","teamID":"0"},"PlayerNumber30":{"x":"179.897766","y":"186.151382","yaw":"245.162994","pitch":"0.000000","teamID":"0"},"PlayerNumber31":{"x":"112.125000","y":"197.460602","yaw":"186.024124","pitch":"0.000000","teamID":"0"}}}';
let PositionArray = [];

function ColorDot(PositionArray) {
  if (PositionArray.teamID == 1) return "red";
  else return "blue";
}

function MyForEach(item) {
  PositionArray.push(item[1]);
  console.log(item);
}

let JsonObject = JSON.parse(JsonString);
const PlayerListObject = JsonObject.playerlist;
const EntryArray = Object.entries(PlayerListObject);
EntryArray.forEach(MyForEach);

function RefreshingDots() {
  const [updateInterval, SetUpdateInterval] = useState(0);

  useEffect(() => {
    const interval = setInterval(() => {
      SetUpdateInterval(updateInterval + 1);
    }, 100);

    return () => clearInterval(interval);
  });

  const listItems = PositionArray.map((Position) => (
    <Circle
      key={parseFloat(Position.x)} //Replace this with an actual key
      x={parseFloat(Position.x)}
      y={parseFloat(Position.y)}
      radius={1}
      fill={ColorDot(Position)}
    />
  ));
  return (
    <>
      <Stage width={window.innerWidth} height={window.innerHeight}>
        <Layer>{listItems}</Layer>
      </Stage>
    </>
  );
}

export default RefreshingDots;
