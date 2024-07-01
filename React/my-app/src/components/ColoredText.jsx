import { useState } from "react";
import "./ColoredText.css";

function StartTimer(SetToggleState) {
  let LocalToggleState = false;
  setInterval(() => {
    SetToggleState(!LocalToggleState);
    LocalToggleState = !LocalToggleState;
  }, 1000);
}

function ColoredText() {
  const [ToggleState, SetToggleState] = useState(0);

  if (ToggleState)
    return (
      <>
        <div id="ColoredTextDiv">
          <h1>Toggle State</h1>
        </div>
      </>
    );

  return (
    <h1
      onClick={() => {
        StartTimer(SetToggleState);
      }}
    >
      Hello
    </h1>
  );
}

export default ColoredText;
