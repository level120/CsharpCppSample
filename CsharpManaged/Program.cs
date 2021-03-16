using System;
using System.Runtime.InteropServices;

namespace CsharpManaged
{
    /// <remarks>https://www.sysnet.pe.kr/2/0/710</remarks>
    public partial class Program
    {
        public static OnErrorCallback GcGuardOnErrorCallback;
        public static OnSuccessCallback GcGuardOnSuccessCallback;

        public static void Main(string[] args)
        {
            // 런타임 중 GC 수집 방지
            GcGuardOnErrorCallback = OnError;
            GcGuardOnSuccessCallback = OnSuccess;

            // Binding callback, UnmanagedCppLib -> delegates.cpp -> SetCallback() 실행
            SetCallback(GcGuardOnErrorCallback, GcGuardOnSuccessCallback);

            Console.ReadLine();
        }
    }

    #region C++ DLL과 상호작용할 영역 시작

    /// <remarks>https://forum.dotnetdev.kr/t/c-dll-c-callback/524/6</remarks>
    /// <remarks>https://www.sysnet.pe.kr/2/0/11099</remarks>
    public partial class Program
    {
        public delegate void OnErrorCallback(int errCode, string errText);
        public delegate void OnSuccessCallback(int id, string keyword);

        [DllImport("UnmanagedCppLib")]
        public static extern void SetCallback(
            OnErrorCallback errorCallback, OnSuccessCallback successCallback);

        public static void OnError(int errCode, string errText) =>
            Console.WriteLine($"!!!!!!!!!!!!!!!!!!! OnError {errText}");

        public static void OnSuccess(int id, string keyword) =>
            Console.WriteLine($"############## OnSuccess {keyword}");
    }

    #endregion C++ DLL과 상호작용할 영역 종료
}
