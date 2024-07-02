import "./Player.css"
function ReturnTeamColor(x) {
    if (x[0] == "PlayerNumber0") return "green"
    if (x[1].teamID == "1") return "blue"
    else return "red"
}


function PlayerObject(PlayerEntry) {


    let PlayerInfo = Object.entries(PlayerEntry)[0][1]

    console.log(PlayerInfo)

    return <>
        <div key={PlayerInfo[0]} className="PlayerBaseDiv" style={{
            top: parseFloat(PlayerInfo[1].x),
            left: parseFloat(PlayerInfo[1].y),
            backgroundColor: `${ReturnTeamColor(PlayerInfo)}`,
            rotate:`${PlayerInfo[1].yaw}deg`
        }} >
            <div className="ViewDirectionDiv" ></div>
        </div>
    </>
}

export default PlayerObject;