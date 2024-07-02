import { useState, useEffect } from "react";
import RadarBase from "./RadarBase";
import PlayerObject from './Player.jsx'

// Get request function
async function SimpleTextFetch(url) {
  let myHeader = new Headers();
  let options = { method: "GET", headers: myHeader, mode: "cors" };
  return fetch(url, options).then((response) => response.text());
}

// Main App "Wrapper"
function App() {
    const [PlayerArray, SetPlayerArray] = useState([]);

    async function UpdatePlayerArray() {
        let JsonString = await SimpleTextFetch("http://localhost:4000/get");
        let JsonObj = Object.entries(Object.entries(JSON.parse(JsonString))[0][1]);

        SetPlayerArray(JsonObj);
    }

    // useEffect is called for events that dont effect the state immediately.
    // In this case, we use it to update the player array which has to wait for the get request.
    // This function is called two times on initial load up, and then acts as a callback for whenever PlayerArray is changed.
    // So this is essentially an infinite callback loop; it gets called everytime the PlayerArray changes and then it changes the PlayerArray.
    useEffect(() => {
        UpdatePlayerArray();
    }, [PlayerArray]);

    // This check will return when you first load up and the PlayerArray has not been fetched yet.
    if (Object.entries(PlayerArray).length < 1) return <h1>NoPlayerData</h1>;

    // LocalPlayer is always player 0 in the PlayerArray. Save that for later.
    let LocalPlayerInfo = PlayerArray[0]

    // Creates a list of my custom "PlayerOject" React components. 1 for each player in the array
    // We pass the current player info as PlayerEntry and pass the LocalPlayerInfo from above.
    // It is neccessary to pass the LocalPlayerInfo aswell in order to calculate the relative position of enemies to the player.
    const listItems = PlayerArray.map((x) => (
        <PlayerObject PlayerEntry={x} LocalPlayerInfo={LocalPlayerInfo} />
    ));

    // If all has worked; return the RadarBase (The gray background + grid lines) and the list of all the custom PlayerObjects.
    // Boom, done.
  return (
      <>
      <RadarBase/>
      <div>{listItems}</div>
    </>
  );
}

export default App;