document.addEventListener("DOMContentLoaded", function () {
    const parkingLot = document.getElementById("parking-lot");

    // Simulated data (0 represents available, 1 represents occupied)
    const parkingData = [0, 1, 0, 0, 1];

    // Generate parking spaces
    for (let i = 0; i < parkingData.length; i++) {
        const space = document.createElement("div");
        space.className = "space";
        space.textContent = `Space ${i + 1}`;

        if (parkingData[i] === 0) {
            space.classList.add("available");
        } else {
            space.classList.add("occupied");
        }

        space.addEventListener("click", function () {
            if (parkingData[i] === 0) {
                parkingData[i] = 1;
                space.classList.remove("available");
                space.classList.add("occupied");
            } else {
                parkingData[i] = 0;
                space.classList.remove("occupied");
                space.classList.add("available");
            }
        });

        parkingLot.appendChild(space);
    }
});
