import "./Player.css"
function ReturnTeamColor(x) {
    if (x[0] === "PlayerNumber0") return "green"
    if (x[1].teamID === "1") return "blue"
    else return "red"
}

// Takes the CurrentPlayerInfo from the PlayerArray, and takes the "LocalPlayerInfo", and returns the relative coordinates of the first to the second
// (Realistically this dosen't have to be the local player. This function will just normalize the coordinates relative to the specified player)
function NormalizeAroundPlayer(CurrentPlayerInfo, LocalPlayerInfo) {

    // Have to do structured clone because using normal assignment dosent work 
    let NormalizedCurrentPlayer = structuredClone(CurrentPlayerInfo);

    // Normalzing the return
    NormalizedCurrentPlayer[1].x = CurrentPlayerInfo[1].x - LocalPlayerInfo[1].x
    NormalizedCurrentPlayer[1].y = CurrentPlayerInfo[1].y - LocalPlayerInfo[1].y

    // Done
    return NormalizedCurrentPlayer
}

function PlayerObject({ PlayerEntry, LocalPlayerInfo }) {

    // Using the normalized coorinates to draw the dots
    let NormalizedPlayerInfo = NormalizeAroundPlayer(PlayerEntry, LocalPlayerInfo);

    return <>
        <div key={NormalizedPlayerInfo[0]} className="PlayerBaseDiv" style={{
            // Setting the "coordinates" of the div using the NormalizedPlayerInfo.
            // By default the NormalizePlayerInfo will give 0-based coordinates, but because we
            // are displaying on a 500x500 grid we just add 248 (not 250 because the radius of the player 5) and it is centered
            // (It isnt perfect because technically we the coordinates entered is the top left of the player circle, so its a bit off)
            left: parseFloat(NormalizedPlayerInfo[1].x) + 248, 
            top: parseFloat(NormalizedPlayerInfo[1].y + 248),
            // Setting the background color of the div dynamically using jsx syntax and custom function
            backgroundColor: `${ReturnTeamColor(NormalizedPlayerInfo)}`,
            // This just works
            rotate: `${NormalizedPlayerInfo[1].yaw}deg`
        }} >
            {/*Just a stupid div that rotates with the player. Could def use improvement*/}
            <div className="ViewDirectionDiv" ></div>
        </div>
    </>
}

export default PlayerObject;